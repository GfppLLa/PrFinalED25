bash 

#!/usr/bin/env bash
set -euo pipefail

#nome do executavel
EXECUTABLE="PrFinalED25"
#pasta do build
BUILD_DIR="build"
#caminho completo para build
BUILD_PATH="$(pwd)/${BUILD_DIR}/${EXECUTABLE}"

#cria e entra na pasta build
mkdir -p "${BUILD_DIR"
cd "${BUILD_PATH}"

if [[ ! -f "$EXECUTABLE" ]]; then 
    echo "Compilando o executável..."
    cmake ..
#compila de fato
    make --build .
    echo "Compilação concluída. Executável criado em: $BUILD_PATH"
elif [[ -f "$EXECUTABLE" && ! -x "$EXECUTABLE" ]]; then
    echo "O executável existe, mas não é executável. Tornando-o executável..."
    chmod +x "$EXECUTABLE"
    echo "Agora o executável é executável."
elif [[ -f "$EXECUTABLE" && -x "$EXECUTABLE" ]]; then
    echo "O executável já existe e é executável. Nenhuma ação necessária."
    exit 0
fi
else
    echo "O executável já existe. Removendo-o..."
    rm -f "$EXECUTABLE"
fi

echo "Executando o programa ${EXECUTABLE}...$*"
exec "EXECUTABLE" "$@"
echo "Programa ${EXECUTABLE} finalizado."

