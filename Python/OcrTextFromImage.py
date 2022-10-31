# pip install pytesseract
import pytesseract
from PIL import Image
 
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'
 
t=Image.open("img.png")
text = pytesseract.image_to_string(t, config='')
print(text)
