/*************************************************************************/
/*  noise.cpp                                                            */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2016 Juan Linietsky, Ariel Manzur.                 */
/* This file is (c) 2016 Marc Gilleron <moc.liamg@norellig.cram>         */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "noise.h"


FastNoise::FastNoise() : Reference() {
    
}

void FastNoise::set_cellular_noise_lookup(Ref<FastNoise> other_noise) {

    _cellular_lookup_ref = other_noise;

    if (_cellular_lookup_ref.is_null())
        _noise.SetCellularNoiseLookup(NULL);
    else
        _noise.SetCellularNoiseLookup(&_cellular_lookup_ref->_noise);
}

void FastNoise::_bind_methods() {
    
	ClassDB::bind_method(D_METHOD("set_seed", "seed"), &FastNoise::set_seed);
	ClassDB::bind_method(D_METHOD("get_seed"), &FastNoise::get_seed);

	ClassDB::bind_method(D_METHOD("set_noise_type", "type"), &FastNoise::set_noise_type);
	ClassDB::bind_method(D_METHOD("set_interpolation", "interp"), &FastNoise::set_interpolation);
	ClassDB::bind_method(D_METHOD("set_frequency", "freq"), &FastNoise::set_frequency);
	ClassDB::bind_method(D_METHOD("set_fractal_gain", "gain"), &FastNoise::set_fractal_gain);
	ClassDB::bind_method(D_METHOD("set_fractal_type", "type"), &FastNoise::set_fractal_type);
	ClassDB::bind_method(D_METHOD("set_fractal_octaves", "octave_count"), &FastNoise::set_fractal_octaves);
	ClassDB::bind_method(D_METHOD("set_fractal_lacunarity", "lacunarity"), &FastNoise::set_fractal_lacunarity);
	ClassDB::bind_method(D_METHOD("set_cellular_distance_function", "func"), &FastNoise::set_cellular_distance_function);
	ClassDB::bind_method(D_METHOD("set_cellular_return_type", "ret"), &FastNoise::set_cellular_return_type);
	ClassDB::bind_method(D_METHOD("set_cellular_noise_lookup", "other_noise"), &FastNoise::set_cellular_noise_lookup);

	ClassDB::bind_method(D_METHOD("get_noise_2d", "x", "y"), &FastNoise::get_noise_2d);
	ClassDB::bind_method(D_METHOD("get_noise_2dv", "pos"), &FastNoise::get_noise_2dv);
	ClassDB::bind_method(D_METHOD("get_noise_3d", "x", "y", "z"), &FastNoise::get_noise_3d);
	ClassDB::bind_method(D_METHOD("get_noise_3dv", "pos"), &FastNoise::get_noise_3dv);
	ClassDB::bind_method(D_METHOD("get_simplex_4d", "x", "y", "z", "w"), &FastNoise::get_simplex_4d);
	ClassDB::bind_method(D_METHOD("get_white_noise_4d", "x", "y", "z", "w"), &FastNoise::get_white_noise_4d);
    // TODO Bind intermediary functions?

    BIND_CONSTANT( TYPE_VALUE );
    BIND_CONSTANT( TYPE_VALUE_FRACTAL );
    BIND_CONSTANT( TYPE_GRADIENT );
    BIND_CONSTANT( TYPE_GRADIENT_FRACTAL );
    BIND_CONSTANT( TYPE_SIMPLEX );
    BIND_CONSTANT( TYPE_SIMPLEX_FRACTAL );
    BIND_CONSTANT( TYPE_CELLULAR );
    BIND_CONSTANT( TYPE_CELLULAR_HQ );
    BIND_CONSTANT( TYPE_WHITE_NOISE );

    BIND_CONSTANT( INTERP_LINEAR );
    BIND_CONSTANT( INTERP_QUINTIC );
    BIND_CONSTANT( INTERP_HERMITE );

    BIND_CONSTANT( FRACTAL_FBM );
    BIND_CONSTANT( FRACTAL_BILLOW );
    BIND_CONSTANT( FRACTAL_RIGID_MULTI );

    BIND_CONSTANT( DISTANCE_EUCLIDEAN );
    BIND_CONSTANT( DISTANCE_MANHATTAN );
    BIND_CONSTANT( DISTANCE_NATURAL );

    BIND_CONSTANT( RETURN_CELL_VALUE );
    BIND_CONSTANT( RETURN_NOISE_LOOKUP );
    BIND_CONSTANT( RETURN_DISTANCE_2_CENTER );
    BIND_CONSTANT( RETURN_DISTANCE_2_CENTER_X_VALUE );
    BIND_CONSTANT( RETURN_DISTANCE_2_CENTER_SQ );
    BIND_CONSTANT( RETURN_DISTANCE_2_CENTER_SQ_X_VALUE );
    BIND_CONSTANT( RETURN_DISTANCE_2_EDGE );
    BIND_CONSTANT( RETURN_DISTANCE_2_EDGE_X_VALUE );
    BIND_CONSTANT( RETURN_DISTANCE_2_EDGE_SQ );
    BIND_CONSTANT( RETURN_DISTANCE_2_EDGE_SQ_X_VALUE );

}



