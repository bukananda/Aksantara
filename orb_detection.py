import cv2 as cv
import matplotlib.pyplot as plt

# Membaca gambar
img = cv.imread('simple.jpg',0)

# Inisialisasi ORB
orb = cv.ORB_create()

# Membuat keypoint dan menghitung deskriptor
kp, dc = orb.detectAndCompute(img, None)

# Menggambar keypoint pada gambar
img2 = cv.drawKeypoints(img, kp, None, flags=cv.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

# Menampilkan gambar dengan keypoint
plt.imshow(img2)
plt.show()