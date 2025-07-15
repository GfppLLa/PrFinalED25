#!/usr/bin/env bash
set -euo pipefail

# nome do executável (deve bater com add_executable no CMakeLists)
EXECUTABLE="PrFinalED25"

# pasta de build (relative ao diretório do script)
BUILD_DIR="build"

# caminho completo para o binário dentro de BUILD_DIR
BUILD_PATH="${BUILD_DIR}/${EXECUTABLE}"

# 1) cria e entra na pasta de build
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

# 2) verifica existência e permissões do executável
if [[ ! -f "${EXECUTABLE}" ]]; then
    echo "Compilando o executável..."
    cmake ..
    cmake --build .
    echo "Compilação concluída. Executável criado em: ${BUILD_PATH}"

elif [[ -f "${EXECUTABLE}" && ! -x "${EXECUTABLE}" ]]; then
    echo "O executável existe, mas não é executável. Tornando-o executável..."
    chmod +x "${EXECUTABLE}"
    echo "Agora o executável é executável."

else
    echo "O executável já existe e é executável. Pulando compilação."
fi

# 3) executa o programa, repassando quaisquer argumentos
echo "==> executando ${BUILD_PATH} $*"
exec "./${EXECUTABLE}" "$@"
