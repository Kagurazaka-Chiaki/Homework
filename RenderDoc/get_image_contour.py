""" This script is used to calculate the percentage of the contour area in the image. """

import os
import numpy as np
import cv2 as cv


def get_image_file_list(path):
    """Return a list of image files."""
    image_file_list = []
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith(".jpg") or file.endswith(".png"):
                image_file_list.append(os.path.join(root, file))
    return image_file_list


def get_image_list(image_file_list: list[str]):
    """Return a list of images."""
    image_list = []
    for image_file in image_file_list:
        image = cv.imread(image_file)
        image_list.append(image)
    return image_list


def image_subprocess(image: cv.typing.MatLike):
    """Calculate the percentage of the contour area in the image."""
    height, width = image.shape[:2]
    total_area = height * width

    hsv = cv.cvtColor(image, cv.COLOR_RGB2HSV)

    lower_color = np.array([60, 100, 200])
    upper_color = np.array([90, 255, 255])
    mask1 = cv.inRange(hsv, lower_color, upper_color)

    lower_color = np.array([60, 200, 200])
    upper_color = np.array([100, 255, 255])
    mask2 = cv.inRange(hsv, lower_color, upper_color)

    mask = cv.bitwise_or(mask1, mask2)
    kernel = np.ones((5, 5), np.uint8)
    mask = cv.morphologyEx(mask, cv.MORPH_CLOSE, kernel)

    contours, hierarchy = cv.findContours(
        mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE
    )

    cont_sum = 0
    for _, cnt in enumerate(contours):
        area = cv.contourArea(cnt)
        cont_sum += area
    print(f"{cont_sum / total_area * 100:.2f}%")


def main():
    """Main function."""
    l = get_image_list(get_image_file_list("img"))
    for i in l:
        image_subprocess(i)


if __name__ == "__main__":
    main()
