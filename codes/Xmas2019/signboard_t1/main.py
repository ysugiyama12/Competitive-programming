import sys
from PIL import Image, ImageDraw


if __name__ == "__main__":
    # 枠線の太さ(二本分)
    waku_w2 = 32

    # 枠にはめ込む写真
    photo = Image.open('./design.png')
    draw = ImageDraw.Draw(photo)
    draw.line((350, 200, 450, 100), fill=(255, 255, 0), width=10)
    photo.show()