from PIL import Image
import numpy as np

# Load and resize
img = Image.open("ttlogo_400.png").convert("RGB").resize((128, 160))
pixels = np.array(img)

# Convert with explicit int() to avoid NumPy type issues
def color565(r, g, b):
    r, g, b = int(r), int(g), int(b)
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3)

# Fill the array
rgb565 = []
for y in range(160):
    row = []
    for x in range(128):
        r, g, b = pixels[y][x]
        row.append(color565(r, g, b))
    rgb565.append(row)

# Write header
with open("image.h", "w") as h:
    h.write("#ifndef IMAGE_H\n#define IMAGE_H\n\n")
    h.write("#include <stdint.h>\n\n")
    h.write("extern const uint16_t image[160][128];\n\n")
    h.write("#endif\n")

# Write source
with open("image.c", "w") as c:
    c.write('#include "image.h"\n\n')
    c.write("const uint16_t image[160][128] = {\n")
    for row in rgb565:
        c.write("    {" + ", ".join(f"0x{val:04X}" for val in row) + "},\n")
    c.write("};\n")
