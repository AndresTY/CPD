import planets
import planets_cy
import timer

py = timer.timer(planets.main, iters=4000000)
cy = timer.timer(planets_cy.main, iters=4000000)

print(py)
print(cy)
print(f'mejor: {py/cy}')
