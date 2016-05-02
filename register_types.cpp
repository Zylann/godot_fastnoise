#include "register_types.h"
#include "object_type_db.h"

#include "noise.h"


void register_fastnoise_types() {

    ObjectTypeDB::register_type<FastNoise>();
}


void unregister_fastnoise_types() {

}


