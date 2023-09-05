import qrcode_terminal
import socket
import time
import os

# Get local ip
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.connect(("8.8.8.8", 80))
ip = s.getsockname()[0]
s.close()

# Write local ip to local_ip.js
current_directory = os.path.dirname(os.path.realpath(__file__))
relative_path = "../rosboard/html/module/local_ip.js"
file_path = os.path.join(current_directory, relative_path)

with open (file_path, "w") as f:
  print('Writing local ip to local_ip.js')
  f.write(f'export let local_ip = "{ip}";')

# Generate QR code in terminal
url = "http://" + ip + ":8888"
time.sleep(2.5)
qrcode_terminal.draw(url)