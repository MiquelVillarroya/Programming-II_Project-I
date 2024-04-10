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
private:
	Layer capa;

public:
	GameObject() : capa(Layer::Scene){}
	void setLayer(Layer l) {
		capa = l;
	}
	Layer layer() const {
		return capa;
	}
};

// It counts the number of objects in the parameter 'objects' that are in layer 'l'
int countGameObjectsInLayer(const GameObject *objects, int numObjects, Layer l)
{
	// TODO
	int count = 0;
	for (int i = 0; i < numObjects; ++i) {
		if (objects[i].layer() == l) count++;
	}

	return count;
}

#endif
