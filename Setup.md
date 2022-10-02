# Setup

## Drogon

### Using `docker`

```bash
./scripts/docker/start-ssh.sh
```

### Using `nix-shell`

Step 1: Install [nix](https://nixos.org/download.html)

Step 2: Start Shell

```bash
nix-shell
```

### Using `vcpkg`

Step 1: Install [vcpkg]

Step 2: Install drogon

```bash
vcpkg install drogon
```

Step 3: Configure env (on macOS/linux)

```bash
export VCPKG_ROOT="$HOME/vcpkg"
export CMAKE_PREFIX_PATH="$HOME/vcpkg/installed/arm64-osx/include:$CMAKE_PREFIX_PATH"
export CPLUS_INCLUDE_PATH="$HOME/vcpkg/installed/arm64-osx/include:$CPLUS_INCLUDE_PATH"
export Drogon_DIR="$HOME/vcpkg/installed/arm64-osx/share/drogon"
for d in $HOME/vcpkg/installed/arm64-osx/tools/*; do PATH="$d:$PATH"; done
```

---

## Test Setup

```bash
drogon_ctl --version

# (or)

dg_ctl --version
```
