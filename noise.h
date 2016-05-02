#ifndef FASTNOISE_NOISE_H
#define FASTNOISE_NOISE_H

#include <reference.h>
#include "lib/FastNoise.h"

typedef fastnoise::FastNoise _FastNoise;

class FastNoise : public Reference {
    OBJ_TYPE(FastNoise, Reference);

public:

    // Enums Godot-style (same values)

    enum Type {
        TYPE_VALUE = _FastNoise::Value,
        TYPE_VALUE_FRACTAL = _FastNoise::ValueFractal,
        TYPE_GRADIENT = _FastNoise::Gradient,
        TYPE_GRADIENT_FRACTAL = _FastNoise::GradientFractal,
        TYPE_SIMPLEX = _FastNoise::Simplex,
        TYPE_SIMPLEX_FRACTAL = _FastNoise::SimplexFractal,
        TYPE_CELLULAR = _FastNoise::Cellular,
        TYPE_CELLULAR_HQ = _FastNoise::CellularHQ,
        TYPE_WHITE_NOISE = _FastNoise::WhiteNoise
    };

    enum Interpolation {
        INTERP_LINEAR = _FastNoise::InterpLinear,
        INTERP_QUINTIC = _FastNoise::InterpQuintic,
        INTERP_HERMITE = _FastNoise::InterpHermite
    };

    enum FractalType {
        FRACTAL_FBM = _FastNoise::FBM,
        FRACTAL_BILLOW = _FastNoise::Billow,
        FRACTAL_RIGID_MULTI = _FastNoise::RigidMulti
    };

    enum CellularDistanceFunction {
        DISTANCE_EUCLIDEAN = _FastNoise::Euclidean,
        DISTANCE_MANHATTAN = _FastNoise::Manhattan,
        DISTANCE_NATURAL = _FastNoise::Natural
    };

    enum CellularReturnType {
        RETURN_CELL_VALUE = _FastNoise::CellValue,
        RETURN_NOISE_LOOKUP = _FastNoise::NoiseLookup,
        RETURN_DISTANCE_2_CENTER = _FastNoise::Distance2Center,
        RETURN_DISTANCE_2_CENTER_X_VALUE = _FastNoise::Distance2CenterXValue,
        RETURN_DISTANCE_2_CENTER_SQ = _FastNoise::Distance2CenterSq,
        RETURN_DISTANCE_2_CENTER_SQ_X_VALUE = _FastNoise::Distance2CenterSqXValue,
        RETURN_DISTANCE_2_EDGE = _FastNoise::Distance2Edge,
        RETURN_DISTANCE_2_EDGE_X_VALUE = _FastNoise::Distance2EdgeXValue,
        RETURN_DISTANCE_2_EDGE_SQ = _FastNoise::Distance2EdgeSq,
        RETURN_DISTANCE_2_EDGE_SQ_X_VALUE = _FastNoise::Distance2EdgeSqXValue
    };
    
    FastNoise();

    // Methods (Godot-style mappings to FastNoise)

    int get_seed() { return _noise.GetSeed(); } // TODO should be const
    void set_seed(int seed) { _noise.SetSeed(seed); }

    void set_noise_type(Type noise_type) { _noise.SetNoiseType((_FastNoise::NoiseType)noise_type); }
    void set_interpolation(Interpolation interp) { _noise.SetInterp((_FastNoise::Interp)interp); }
    void set_frequency(float freq) { _noise.SetFrequency(freq); }
    void set_fractal_gain(float gain) { _noise.SetFractalGain(gain); }
    void set_fractal_type(FractalType type) { _noise.SetFractalType((_FastNoise::FractalType)type); }
    void set_fractal_octaves(unsigned int octave_count) { _noise.SetFractalOctaves(octave_count); }
    void set_fractal_lacunarity(float lacunarity) { _noise.SetFractalLacunarity(lacunarity); }
    void set_cellular_distance_function(CellularDistanceFunction func) { _noise.SetCellularDistanceFunction((_FastNoise::CellularDistanceFunction)func); }
    void set_cellular_return_type(CellularReturnType ret) { _noise.SetCellularReturnType((_FastNoise::CellularReturnType)ret); }

    // TODO Q: how can I do that properly?
    void set_cellular_noise_lookup(Ref<FastNoise> other_noise);

    // 2D

    float get_noise_2d(float x, float y) { return _noise.GetNoise(x, y); }

    //float get_gradient_2d(float x, float y) { return _noise.GetGradient(x, y); }
    //float get_simplex_2d(float x, float y) { return _noise.GetSimplex(x, y); }
    //float get_cellular_2d(float x, float y) { return _noise.GetCellular(x, y); }
    //float get_cellular_hq_2d(float x, float y) { return _noise.GetCellularHQ(x, y); }
    //float get_white_noise_2d(float x, float y) { return _noise.GetWhiteNoise(x, y); }
    //float get_value_2d(float x, float y) { return _noise.GetValue(x, y); }

    // 3D

    float get_noise_3d(float x, float y, float z) { return _noise.GetNoise(x, y, z); }

    //float get_gradient_3d(float x, float y, float z) { return _noise.GetGradient(x, y, z); }
    //float get_simplex_3d(float x, float y, float z) { return _noise.GetSimplex(x, y, z); }
    //float get_cellular_3d(float x, float y, float z) { return _noise.GetCellular(x, y, z); }
    //float get_cellular_hq_3d(float x, float y, float z) { return _noise.GetCellularHQ(x, y, z); }
    //float get_white_noise_3d(float x, float y, float z) { return _noise.GetWhiteNoise(x, y, z); }
    //float get_value_2d(float x, float y, float z) { return _noise.GetValue(x, y, z); }

    // 4D

    float get_simplex_4d(float x, float y, float z, float w) { return _noise.GetSimplex(x, y, z, w); }
    float get_white_noise_4d(float x, float y, float z, float w) { return _noise.GetWhiteNoise(x, y, z, w); }

    // Convenience

    float get_noise_2dv(Vector2 pos) { return _noise.GetNoise(pos.x, pos.y); }
    float get_noise_3dv(Vector3 pos) { return _noise.GetNoise(pos.x, pos.y, pos.z); }


protected:
    static void _bind_methods();

private:
    _FastNoise _noise;
    Ref<FastNoise> _cellular_lookup_ref;

};

// Make Variant happy with custom enums
VARIANT_ENUM_CAST(FastNoise::Type);
VARIANT_ENUM_CAST(FastNoise::FractalType);
VARIANT_ENUM_CAST(FastNoise::Interpolation);
VARIANT_ENUM_CAST(FastNoise::CellularDistanceFunction);
VARIANT_ENUM_CAST(FastNoise::CellularReturnType);


#endif // FASTNOISE_NOISE_H

