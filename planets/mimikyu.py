import planets
import planets_cy
import timer
from objetc_planet import Planet

<<<<<<< HEAD
py = timer.timer(planets.settings, Planet(), iters=4000000)
cy = timer.timer(planets_cy.settings, Planet(), iters=4000000)
=======
py = timer.時間(planets.main, iters=4000000)
cy = timer.時間(planets_cy.main, iters=4000000)
>>>>>>> refs/remotes/origin/main

print(py)
print(cy)
print(f'mejor: {py/cy}')
