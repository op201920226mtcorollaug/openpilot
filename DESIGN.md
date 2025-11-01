# Design Document for this automated repository

* The repository is powered by GitHub Actions.
* The GitHub Action will run a script that will:
  * Clone the `nightly-dev` branch of comma.ai openpilot and `staging-c3-new` branch of sunnypilot.
  * For optimization, the script will use shallow cloning to reduce the amount of data transferred. Just `--depth=1` will be used to clone the latest commit only.
  * The work will be done in `tmp/` of this repository's working directory to not interfere with the repository's main directory.
  * `tmp/` is `gitignore`d to prevent committing temporary files.
  * Apply patches to the cloned repository to support the 6MT TSS2 Corollas.
  * Commit the changes to a new branch in this repository.
  * Branches are named `op-nightly-dev` for openpilot, `sp-release`, `sp-staging`, `sp-dev` for sunnypilot C3X, and `sp-staging-tici` for sunnypilot C3.
* The GitHub Action will run on a schedule (e.g., daily) to ensure the repository is up-to-date with the latest changes from the upstream repositories.
* The repository will have a README.md file that explains how to use the repository, including how to install the patched version of openpilot or sunnypilot on a comma three device.