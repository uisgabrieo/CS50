import qrcode

url = input("U: ")
img = qrcode.make(url)
img.save("Qr.png", "PNG")
