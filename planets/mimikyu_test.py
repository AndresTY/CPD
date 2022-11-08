import planets
import planets_cy
import timer


py = timer.timer(planets.settings, planets_cy.Planet(), iters=4000000)
cy = timer.timer(planets_cy.settings, planets_cy.Planet(), iters=4000000)

print(py)
print(cy)
print(f'mejor: {py/cy}')
