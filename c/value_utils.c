#include <glib-2.0/glib.h>
#include <glib-2.0/glib-object.h>
#include <gee-0.8/gee.h>
#include <prosody.h>

ProsodyDataData *prosody_data_object_data_value_to_data(ProsodyDataObjectData *self, GValue *val) {
    if(G_VALUE_HOLDS(val, GEE_TYPE_LIST)) {
        return PROSODY_DATA_DATA(prosody_data_list_new(GEE_LIST(g_value_get_object(val))));
    }
    if(G_VALUE_HOLDS(val, GEE_TYPE_MAP)) {
        return PROSODY_DATA_DATA(prosody_data_mapping_new(GEE_MAP(g_value_get_object(val)), NULL));
    }
    if(G_VALUE_HOLDS_OBJECT(val)) {
        return PROSODY_DATA_DATA(prosody_data_object_data_new(g_value_get_object(val)));
    }
    return PROSODY_DATA_DATA(prosody_data_literal_new(val));
}