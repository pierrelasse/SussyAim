import os
import binascii

path = input("Path: ")

if not os.path.isfile(path):
    print("The file does not exist!")
    input()
    exit()

hex_data: str = None

with open(path, "rb") as f:
    hex_data = binascii.hexlify(f.read()).decode("utf-8")
    
if hex_data == None:
    print("Could not hexlify")
    input()
    exit()

with open(path + ".txt", "w") as f:
    f.write(f"{{\n    {', '.join([f'0x{hex_data[i:i+2]}' for i in range(0, len(hex_data), 2)])}\n}}")
    print("Success!")
        
input()
