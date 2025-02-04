import struct

with open('input.txt', 'r') as txt_file:
    with open('input.bin', 'wb') as bin_file:
        for line in txt_file:
            num = int(line.strip())
            bin_file.write(struct.pack('I', num))