#!/usr/bin/env python

import sys
sys.path.append("../gen-py")

from helloworld import HelloWorld
from helloworld.ttypes import *

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

import socket

class HelloWorldHandler:
	def __init__(self):
		self.log = {}

	def sayHello(self):
		print "sayHello()"
		return "hello world "

handler = HelloWorldHandler()

processor = HelloWorld.Processor(handler)
transport = TSocket.TServerSocket('127.0.0.1',9090)
tfactory = TTransport.TBufferedTransportFactory()
pfactory = TBinaryProtocol.TBinaryProtocolFactory()

server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)

print "Starting python server..."
server.serve()