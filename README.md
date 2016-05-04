FastNoise for Godot Engine
=============================

This is an integration of the [FastNoise C++ library](https://github.com/Auburns/FastNoise) for Godot Engine.
It uses Simplex Noise for some of its generators, which is [patented](https://www.google.com/patents/US6867776) for image generation.
If you want to avoid the patent, you can try OpenSimplex, for which I also made a [module](https://github.com/Zylann/godot_opensimplex).

I still prefer FastNoise because it has more features, doesn't allocates dynamic memory and works with a single class.
