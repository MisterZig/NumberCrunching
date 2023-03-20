import numpy as np
from PIL import Image

def readImageBrightnes(imagePath):
    image = Image.open(imagePath).convert('L') # convert to grayscale (for other channels use 'RGB' or 'CMYK')
    image = np.array(image)
    image = image.astype(np.float32)
    image = image / 255.0
    return image

from matplotlib import pyplot
imagePath = input("Enter image path: ")

pyplot.imsave("./test.png", readImageBrightnes(imagePath), cmap='gray')