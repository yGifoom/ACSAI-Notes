# correction of the billboard exercise

import cv2
import numpy as np

def cmask(img: np.array, points: int = 4) -> tuple[np.array]:
        
            # define the mouse callback function
    def onClick(event,x,y,flags,param):
        if event == cv2.EVENT_LBUTTONDOWN:
            if len(poly) < points:
                poly.append([x,y])
                cv2.circle(img_copy,(x,y),5 ,(0,0,255),-1)
                cv2.imshow("Mask", img_copy)

    img_copy = img.copy()
    poly = []


    cv2.namedWindow('Mask')
    cv2.setMouseCallback('Mask',onClick)

    # show the image in order to be clicked
    cv2.imshow('Mask', img_copy)
    cv2.waitKey(0)
    print("mask obtained")
    cv2.destroyAllWindows()


    # make mask by filling poly
    mask = np.zeros_like(img)
    cv2.fillConvexPoly(mask, np.int32(poly), (255,255,255))

    return mask, np.bitwise_not(mask)



def bill(base_img: np.array, img2: np.array) -> np.array:

    # define the mouse callback function
    def onClick(event,x,y,flags,param):
        if event == cv2.EVENT_LBUTTONDOWN:
            if len(dst_points) < 4:
                dst_points.append([x,y])
                cv2.circle(img_copy,(x,y),5 ,(0,0,255),-1)
                cv2.imshow('Base Img', img_copy)

    fact = 1
    # resize images
    base_img = cv2.resize(base_img, (base_img.shape[1] * fact, base_img.shape[0] * fact))
    img_copy = base_img.copy()

    # get the image data
    base_h, base_w = base_img.shape[:2]
    img2_h, img2_w = img2.shape[:2]

    # create source and destinations points
    src_points = np.array(
        [
            [0,0],
            [0,img2_h],
            [img2_w,img2_h],
            [img2_w,0]
        ], dtype=np.float32
    )
    dst_points = []

    # define the window for getting the destination points
    cv2.namedWindow('Base Img')
    cv2.setMouseCallback('Base Img',onClick)

    # show the image in order to be clicked
    cv2.imshow('Base Img', base_img)
    cv2.waitKey(0)

    # get the homography matrix
    dst_float = np.array(dst_points,dtype=np.float32)
    H = cv2.getPerspectiveTransform(src_points,dst_float)

    # apply the homography matrix to the image angles
    warped = cv2.warpPerspective(img2, H, (base_w,base_h))

    # create a mask to drop black pixels from the warped image
    mask = np.zeros(base_img.shape, dtype=np.uint8)
    cv2.fillConvexPoly(mask, np.int32(dst_float),(255,255,255))

    # apply the mask to the billboard image

    # invert the mask for removing the colored pixels from the
    # billboard image
    mask = cv2.bitwise_not(mask)
    masked_bill = cv2.bitwise_and(base_img,mask)

    # apply the mask to our second image
    final_img = cv2.bitwise_or(masked_bill, warped)

    cv2.namedWindow('Final Img')
    cv2.imshow('Final Img', final_img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
    return final_img
