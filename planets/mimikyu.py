# python import
from subprocess import check_output
from timeit import repeat
import timer
import planets_cy
import planets
import planets_object
import sys


def principal(steps=4000000, time_span=400):
    planets_list = planets_object.created_solar_system()
    for i in planets_list:
        py = timer.timer(planets.settings, i, time_span, steps)
        cy = timer.timer(planets_cy.settings, i, time_span, steps)

        with(open(f"results/planeta-{steps}.csv", "a")) as archivo:
            archivo.write("{},{:.5f},{:.5f}\n".format(
                steps, py, cy))


if __name__ == '__main__':
    s = 0
    try:
        args = sys.argv[1:]
        for i in range(len(args)):
            if args[i] == '-s':
                i += 1
                s = int(args[i])
        if s:
            principal(s)
        else:
            principal()
    except Exception as E:
        print(E)
