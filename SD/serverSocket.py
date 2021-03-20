#!/usr/bin/env python3

from _thread import *
import socket
import threading
import sys

HOST = '127.0.0.1'
PORT = int(sys.argv[1])

contadorMensagens = 0

print_lock = threading.Lock()


def thread_function(c, addr):
    while True:
        data = c.recv(1024)
        if not data:
            print('Cliente encerrou...')
            print_lock.release()
            break
        message = str(data.decode('ascii'))
        print(str(data.decode('ascii')), 'IP :', addr[0], ' Porta: ', addr[1])
        message = 'Mensagem: '+ str(data.decode('ascii')) + ' recebida!'
        global contadorMensagens
        contadorMensagens += 1
        c.send(message.encode('ascii'))


def Main():
    if not sys.argv[1]:
        print('Argumento da porta faltando!')
        exit(0)
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen(5)
    print('Socket escutando na porta', PORT)
    while True:
        c, addr = s.accept()
        print_lock.acquire()
        
        start_new_thread(thread_function, (c,addr,))
    s.close()

if __name__ == '__main__': 
    Main()
