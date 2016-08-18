#!/usr/bin/python3


class LinkedList():
	"""docstring for LinkedList"""

	class Node:
		"""documentarion. todo: implement"""
		__slots__ = '_content', '_next'

		def __init__(self, content, next):
			self._content = content
			self._next = next

	def __init__(self):
		self._head = None
		self._size = 0
		

	def __len__(self):
		return self._size


	def is_empty(self):
		return (self._size == 0)


	def append(self, content):
		self._head = self.Node(content, self._head)
		self._size += 1


	def head(self):
		return self._head._content if not self.is_empty() else None

	def pop(self):
		if self.is_empty():
			return None
		else:
			item = self._head._content
			self._head = self._head._next
			self._size -= 1
			return item

	def print_it(self):
		print('[', end="")
		temp = self._head
		cont = 0
		while cont < self._size:
			print(str(temp._content) + " ", end="")
			temp = temp._next
			cont += 1
		print(']')



if __name__ == '__main__':
	ll = LinkedList()
	ll.append(1)
	ll.append(2)
	ll.append(3)
	print(ll.head())
	ll.print_it()
	print(ll.pop())
	print(ll.head())
	ll.print_it()
