import binascii

def imgToArr(path):
    with open(path, 'rb') as image_file:
        hex_data = binascii.hexlify(image_file.read()).decode('utf-8')
        print(f"{{\n    {', '.join([f'0x{hex_data[i:i+2]}' for i in range(0, len(hex_data), 2)])}\n}}")

imgToArr(input("Path: "))
