/* ----------------------------------------------------------------------- */
/*                          TYPE YOUR NAME HERE                            */
/* ----------------------------------------------------------------------- */
#ifndef EX2_H
#define EX2_H

// Enumerated type for GameObject's layers
enum class Layer {
	Scene,
	Characters,
	Background,
	Foreground,
	UserInterface
};

// Class for generic game objects
class GameObject
{
	// TODO
};

// It counts the number of objects in the parameter 'objects' that are in layer 'l'
int countGameObjectsInLayer(const GameObject *objects, int numObjects, Layer l)
{
	// TODO
	return 0;
}

#endif
