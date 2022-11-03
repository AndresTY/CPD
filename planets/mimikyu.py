import planets
import planets_cy
import timer
from objetc_planet import Planet

py = timer.timer(planets.settings, Planet(), iters=4000000)
cy = timer.timer(planets_cy.settings, Planet(), iters=4000000)

print(py)
print(cy)
print(f'mejor: {py/cy}')
