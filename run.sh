#!/bin/bash
set -e

# Configuration
OP_REPO="https://github.com/commaai/openpilot.git"
OP_BRANCH="nightly-dev"
OP_DIR="tmp/openpilot"
OP_PATCH_BRANCH="op-nightly-dev"

SP_C3X_REPO="https://github.com/sunnypilot/sunnypilot.git"
SP_C3X_BRANCH="staging"
SP_C3X_DIR="tmp/sunnypilot-c3x"
SP_C3X_PATCH_BRANCH="sp-staging"

SP_C3_REPO="https://github.com/sunnypilot/sunnypilot.git"
SP_C3_BRANCH="staging-tici"
SP_C3_DIR="tmp/sunnypilot-c3"
SP_C3_PATCH_BRANCH="sp-staging-tici"

# Clean up previous run
rm -rf tmp
mkdir -p tmp

# Clone Repositories
echo "Cloning repositories..."
git clone --depth 1 --branch="$OP_BRANCH" "$OP_REPO" "$OP_DIR"
git clone --depth 1 --branch="$SP_C3X_BRANCH" "$SP_C3X_REPO" "$SP_C3X_DIR"
git clone --depth 1 --branch="$SP_C3_BRANCH" "$SP_C3_REPO" "$SP_C3_DIR"

# Apply Patches
echo "Applying patches..."
git -C "$OP_DIR" apply ../../patches/openpilot.patch
echo "Patched openpilot."

git -C "$SP_C3X_DIR" apply ../../patches/sunnypilot.patch
echo "Patched sunnypilot C3X."

git -C "$SP_C3_DIR" apply ../../patches/sunnypilot.patch
echo "Patched sunnypilot C3."


# Commit and Push Changes
echo "Committing and pushing changes..."

# openpilot
cd "$OP_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git remote set-url origin "https://x-access-token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"
git add .
GIT_AUTHOR_DATE='2021-08-08 00:00:00 +0000' GIT_COMMITTER_DATE='2021-08-08 00:00:00 +0000' git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$OP_PATCH_BRANCH" --force
cd -

# sunnypilot C3X
cd "$SP_C3X_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git remote set-url origin "https://x-access-token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"
git add .
GIT_AUTHOR_DATE='2021-08-08 00:00:00 +0000' GIT_COMMITTER_DATE='2021-08-08 00:00:00 +0000' git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$SP_C3X_PATCH_BRANCH" --force
cd -

# sunnypilot C3
cd "$SP_C3_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git remote set-url origin "https://x-access-token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"
git add .
GIT_AUTHOR_DATE='2021-08-08 00:00:00 +0000' GIT_COMMITTER_DATE='2021-08-08 00:00:00 +0000' git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$SP_C3_PATCH_BRANCH" --force
cd -

echo "Script finished."