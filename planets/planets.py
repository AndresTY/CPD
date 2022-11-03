from math import sqrt


def single_step(planet, dt):

    distance = sqrt(planet.x**2 + planet.y**2 + planet.x**2)
    Fx = -planet.x/distance**3
    Fy = -planet.y/distance**3
    Fz = -planet.z/distance**3

    planet.x += dt*planet.vx
    planet.y += dt*planet.vy
    planet.z += dt*planet.vz

    planet.vx += dt * Fx/planet.m
    planet.vy += dt * Fy/planet.m
    planet.vz += dt * Fz/planet.m


def step_time(planet, time_span, n_steps):
    dt = time_span / n_steps

    for _ in range(n_steps):
        single_step(planet, dt)


def settings(miPlanet, dt=5000, iters=1000000):
    step_time(miPlanet, dt, iters)
