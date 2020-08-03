# thanote
never forget, never forgive (or umh maybe forgive if its ok)


## idee
gtk3 fürs ui
sol+lua um es scriptbar zu gestalten
sqlite fürs speichern
gegebenenfalls json als alternative nutzen

### buildsystem
cmake (ja muss sein)
ninja

## building thanote

clonen des repositories

externes build dir erstellen

cmake die die buildsystemdatein erstellen lassen via `cmake ../path/to/thante_src/ -G"Ninja"` anschließend `ninja` ausführen

### using conan 
im build dir:
`conan install .. --build=missing`

see this solution when conan is donwloading/building with the wrong compiler

 https://github.com/conan-io/conan/issues/2760#issuecomment-381397855




