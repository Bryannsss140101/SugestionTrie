# SuggestionTrie

Un proyecto en C++ que implementa un Árbol Trie combinado con un algoritmo de búsqueda en profundidad (DFS) para proporcionar sugerencias rápidas y eficientes basadas en prefijos. Este proyecto es ideal para comprender cómo los Tries, junto con técnicas de recorrido como DFS, pueden resolver problemas prácticos como el autocompletado y la búsqueda predictiva.

## Tabla de Contenidos

1. [Descripción](#descripción)
3. [Funciones](#funciones)
5. [Implementación](#implementación)
6. [Contribuciones](#contribuciones)
7. [Licencia](#licencia)

## Descripción

El **Árbol Trie** es una herramienta eficiente para manejar palabras y encontrar patrones comunes entre ellas, esta estructura se combina con un recorrido especial llamado **Búsqueda en profundidad (DFS)** para encontrar palabras que comiencen con un mismo prefijo.

El sistema permite sugerir palabras de forma rápida y sencilla, siendo ideal para funciones como autocompletado o búsqueda rápida en listas grandes de texto. Es una solución práctica para optimizar tareas que trabajan con muchas palabras.

<img src="assets/images/trie_tree.png" alt="Árbol Trie" width="300"/>

## Funciones

- **insert**: Inserta un nuevo nodo en el árbol.
  ```cpp
  Node *Trie::insert(const std::string &word, Node *node) {
    const auto index = to_index(std::tolower(word[0]));

    if (node == nullptr)
        node = new Node();

    if (word.empty()) {
        node->word_end = true;
        return node;
    }

    node->children[index] = insert(word.substr(1), node->children[index]);
    return node;
  }
- **search**: Buscar un nodo en el árbol.
  ```cpp
    bool Trie::search(const std::string &word, Node *node) {
    const auto index = to_index(std::tolower(word[0]));

    if (node == nullptr)
        return false;

    if (word.empty())
        return node->word_end;

    return search(word.substr(1), node->children[index]);
  }
- **find**: Buscar y retorna un nodo en el árbol.
  ```cpp
    Node *Trie::find(const std::string &word, Node *node) {
    if (node == nullptr || word.empty())
        return node;

    const auto index = to_index(std::tolower(word[0]));
    return find(word.substr(1), node->children[index]);
  }
- **DFS**: Busqueda en profundidad apartir de un nodo.
  ```cpp
    void Trie::DFS(const std::string &prefix, Node *node, std::vector<std::string> &words) {
    if (node == nullptr)
        return;

    if (node->word_end)
        words.push_back(prefix);

    for (int i = 0; i < 27; ++i)
        if (node->children[i] != nullptr) {
            const char c = i == 26 ? ' ' : 'a' + i;
            DFS(prefix + c, node->children[i], words);
        }
    }
  
## Implementación

Para usar este proyecto, clona el repositorio y ejecuta el **main.cpp** desde de CLion.
```bash
git clone https://github.com/Bryannsss140101/SugestionTrie.git
cd SugestionTrie
```

## Contribuciones

¡Las contribuciones son bienvenidas! Si encuentras algún bug o tienes sugerencias de mejora, no dudes en abrir un issue o hacer un pull request. Asegúrate de seguir estas pautas:

1. Forkea el repositorio.
2. Crea una nueva rama **(git checkout -b feature/new-functionality)**.
4. Realiza tus cambios y haz commit **(git commit -m 'prefix: Type of functionality')**.
6. Haz push a tu rama **(git push origin feature/new-functionality)**.
8. Crea un pull request.

## Licencia

Este proyecto está licenciado bajo la **Licencia MIT**. Para más detalles, consulta el archivo [LICENSE](lic/LICENSE.txt).
