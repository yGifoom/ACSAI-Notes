import cv2
import numpy as np
from billboard_ex import bill, cmask

cam_h, cam_w = (480, 640) # webcam dimentions

# take two images
img2 = cv2.imread("data/mario hat.jpg")
# capture video
vid = cv2.VideoCapture(0)
ret, frame = vid.read()

# perspective transform for the whole image
base_img = bill(frame, img2)
# get the masks for part of image 
mask, nmask = cmask(base_img, 8) 

print(type(mask), type(nmask))

# masks for mario hat and background without hat
cut = cv2.bitwise_and(base_img, mask)


while True:
    ret, frame = vid.read()

    # making mask per frame & mask
    bkgr = cv2.bitwise_and(frame, nmask)
    final_img = cv2.bitwise_or(cut, bkgr)
    # display
    cv2.imshow("final_img", final_img)

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

vid.release()
cv2.destroyAllWindows() 