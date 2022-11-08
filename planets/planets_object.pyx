cdef class  Planet(object):
  cdef public double x,y,z,vx,vy,vz,m
  def __cinit__(self,double x, double y, double z, double vx, double vy, double vz, double m):  
    self.x = x
    self.y = y
    self.z = z
    self.vx = vx
    self.vy = vy
    self.vz = vz
    self.m = m
  def __str__(self):
      return f"planeta {self.x}"
  
def created_solar_system():
    tierra = Planet(100*10**3,300*10**3,700*10**3,2.00*10**3,29.87*10**3,0.34*10**3,5.9742*10**24)
    return [tierra]
