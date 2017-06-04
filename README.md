# WebAPI (JUCE Modules)

## Tested Platforms
- macOS (Universal 32-bit/64-bit)
- Windows (32-bit/x64)

---

## Get Started - After Cloning & Forking

On first clone, run the following git commands on the repository.

```bash
# Download the submodules for the first time:
git submodule update --init --recursive
```

At any other point, run the following git commands on the repository.

```bash
# Download the latest code from the submodules, assuming there are changes:
git submodule update --recursive
```

---

## Submodule Dependencies
- https://github.com/WeAreROLI/JUCE

---

## How to Build the Test Application

* Open, build and run the Projucer project.
  * Found under `submodules/JUCE/extras/Projucer/Builds`.
* Open the `WebAPIJUCE/demo/WebAPIJUCEDemo.jucer` file, hit save, and open the appropriate project for your IDE.
