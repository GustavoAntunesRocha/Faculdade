#!/usr/bin/env python3

import socket
import sys

def Main():
    
    host = '127.0.0.1'
  
    port = int(sys.argv[1])
  
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM) 
  
    s.connect((host,port)) 
  
    
    while True: 
        message = input('\nDigite sua mensagem: ')
        s.send(message.encode('ascii')) 
  
        data = s.recv(1024) 
  
        print(str(data.decode('ascii'))) 
  
        ans = input('\nDeseja continuar?(s/n) :') 
        if ans == 's': 
            continue
        else: 
            break
    s.close() 
  
if __name__ == '__main__': 
    Main()