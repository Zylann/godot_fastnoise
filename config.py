

def can_build(platform):
    return True
  
  
def configure(env):
    # FastNoise uses a few C++11 features
    env.Append(SCONS_CXX_STANDARD="c++11")
