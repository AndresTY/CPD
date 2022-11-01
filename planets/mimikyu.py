import planets
import planets_cy
import timer

py = timer.時間(planets.main, iters=4000000)
cy = timer.時間(planets_cy.main, iters=4000000)

print(py)
print(cy)
print(f'mejor: {py/cy}')
