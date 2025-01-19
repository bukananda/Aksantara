import cv2 as cv
import math
import numpy as np

def detect_keypoints(image, threshold=50):
    keypoints = []
    for baris in range(len(image)):
        for kolom in range(len(image[baris])):
            intensitas_p = image[baris,kolom]
            intensitas_tetangga = []
            for i in [(-3,-1),(-3,0),(-3,1),(3,-1),(3,0),(3,1),(-2,2),(2,-2),(2,2),(-2,-2),(-1,3),(0,3),(1,3),(-1,-3),(0,-3),(1,-3)]:
                try:
                    intensitas_tetangga.append(image[baris+i[0],kolom+i[1]])
                except:
                    pass

            if (np.sum(np.array(intensitas_tetangga) > intensitas_p + threshold) >= 12 or np.sum(np.array(intensitas_tetangga) < intensitas_p - threshold) >= 12):
                keypoints.append((kolom, baris))
    return keypoints

def compute_orientation(image, keypoint, radius=5):
    x, y = keypoint
    m01 = 0
    m10 = 0
    for i in range(-radius, radius + 1):
        for j in range(-radius,radius + 1):
            if 0 <= x + i < image.shape[1] and 0 <= y + j < image.shape[0]:
                m01 += (y+j)*image[y+j,x+i]
                m10 += (x+j)*image[y+j,x+i]
            
    orientasi = math.atan2(m01, m10)
    return orientasi

def compute_descriptor(image, keypoint, ort, pattern=20):
    x,y = keypoint
    descriptor = []
    p = [0 for _ in range(4)]
    for _ in range(pattern):
        for i in range(4):
            p[i] = np.random.randint(-5,6)

        p1_x_rot = int(p[0] * math.cos(ort) - p[1] * math.sin(ort))
        p1_y_rot = int(p[0] * math.sin(ort) + p[1] * math.cos(ort))
        p2_x_rot = int(p[2] * math.cos(ort) - p[3] * math.sin(ort))
        p2_y_rot = int(p[2] * math.sin(ort) + p[3] * math.cos(ort))

        try:
            if image[y+p1_y_rot,x+p1_x_rot] < image[y+p2_y_rot,x+p2_x_rot]:
                descriptor.append(1)
            else:
                descriptor.append(0)
        except:
            descriptor.append(0)
    return descriptor

# Membaca gambar
img = cv.imread('simple.jpg',0)

# Mendeteksi keypoint
keypoints = detect_keypoints(img)

# Menghitung orientasi dan deskriptor
kp_or = []
descs = []
for keypoint in keypoints:
    ort = compute_orientation(img, keypoint)
    descriptor = compute_descriptor(img, keypoint, ort)
    kp_or.append((keypoint,ort))
    descs.append(descriptor)

img_kp = cv.drawKeypoints(img, [cv.KeyPoint(x, y, 1) for (x, y), _ in kp_or], None)

cv.imshow("ORB",img_kp)
cv.waitKey(0)
cv.destroyAllWindows()