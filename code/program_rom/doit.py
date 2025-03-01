# init rom.bin with 0xea
rom = bytearray([0xea] * 32768)

# set the reset vector to 0x8000
rom[0x7ffc] = 0x00
rom[0x7ffd] = 0x80

# write the rom to a file
with open('rom.bin', 'wb') as f:
    f.write(rom)