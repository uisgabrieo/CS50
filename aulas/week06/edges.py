from PIL import Image, ImageFilter

before = Image.open("tower.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("edgesOut.bmp")
