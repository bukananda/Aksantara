import threading
import time

def countdown(t):
  while (t >= 0):
    mins, secs = divmod(t, 60)
    timer = '{:02d}:{:02d}'.format(mins, secs)
    print(timer, end="\r")
    time.sleep(1)
    t -= 1
  return "end"

waktu = int(input("Masukkan waktu timer (detik): "))
timer_thread = threading.Thread(target=countdown, args=(waktu,))
timer_thread.start()
print("Timer berjalan di background...")