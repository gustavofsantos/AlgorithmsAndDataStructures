#!/usr/share/python3

from random import randint, choice, random
import sys

class Point:
	def  __init__(self, x, y):
		self.x = x
		self.y = y

	def perturbate(self, dx, dy):
		self.x += dx
		self.y += dy


DATA  = []
X_MAX = 30
Y_MAX = 30
N_MAX = 90

def generate_data(n_clusters):
	centers = []

	for i in range(n_clusters):
		centers.append(Point(randint(0, X_MAX), randint(0, Y_MAX)))


	for c in centers:
		DATA.append(c)

	sign = [1, -1]
	alphas = [1, 2]


	for i in range(N_MAX):
		center = choice(centers)
		signx = choice(sign)
		signy = choice(sign)
		alphax = choice(alphas)
		alphay = choice(alphas)

		center.perturbate(signx*alphax*random(), signy*alphay*random())

		DATA.append(center)


def generate_random_data():
	for i in range(N_MAX):
		DATA.append(Point(randint(0, X_MAX), randint(0, Y_MAX)))


def write_data():
	with open('data.csv', 'w') as file:
		for d in DATA:
			s = '{},{}\n'.format(d.x, d.y)
			file.write(s)


if __name__ == '__main__':
	n_clusters = sys.argv[2] if len(sys.argv) == 3 else sys.argv[1]
	print('[!] Generating data from {} centers...'.format(n_clusters))
	generate_data(int(n_clusters))
	#generate_random_data()
	print('[+] Ok.')
	print('[!] Writing data...')
	write_data()
	print('[+] Ok.')
