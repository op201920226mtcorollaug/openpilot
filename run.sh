#!/bin/bash
set -e

# Configuration
OP_REPO="https://github.com/commaai/openpilot.git"
OP_BRANCH="nightly-dev"
OP_DIR="tmp/openpilot"
OP_PATCH_BRANCH="op-nightly-dev"

SP_C3X_STAGING_REPO="https://github.com/sunnypilot/sunnypilot.git"
SP_C3X_STAGING_BRANCH="staging"
SP_C3X_STAGING_DIR="tmp/sunnypilot-c3x-staging"
SP_C3X_STAGING_PATCH_BRANCH="sp-staging"

SP_C3_STAGING_REPO="https://github.com/sunnypilot/sunnypilot.git"
SP_C3_STAGING_BRANCH="staging-tici"
SP_C3_STAGING_DIR="tmp/sunnypilot-c3-staging"
SP_C3_STAGING_PATCH_BRANCH="sp-staging-tici"

SP_C3X_RELEASE_REPO="https://github.com/sunnypilot/sunnypilot.git"
SP_C3X_RELEASE_BRANCH="release"
SP_C3X_RELEASE_DIR="tmp/sunnypilot-c3x-release"
SP_C3X_RELEASE_PATCH_BRANCH="sp-release"


SP_C3X_DEV_REPO="https://github.com/sunnypilot/sunnypilot.git"
SP_C3X_DEV_BRANCH="dev"
SP_C3X_DEV_DIR="tmp/sunnypilot-c3x-dev"
SP_C3X_DEV_PATCH_BRANCH="sp-dev"

# Clean up previous run
rm -rf tmp
mkdir -p tmp

# Clone Repositories
echo "Cloning repositories..."
git clone --depth 1 --branch="$OP_BRANCH" "$OP_REPO" "$OP_DIR"
git clone --depth 1 --branch="$SP_C3X_STAGING_BRANCH" "$SP_C3X_STAGING_REPO" "$SP_C3X_STAGING_DIR"
git clone --depth 1 --branch="$SP_C3_STAGING_BRANCH" "$SP_C3_STAGING_REPO" "$SP_C3_STAGING_DIR"
git clone --depth 1 --branch="$SP_C3X_RELEASE_BRANCH" "$SP_C3X_RELEASE_REPO" "$SP_C3X_RELEASE_DIR"
git clone --depth 1 --branch="$SP_C3X_DEV_BRANCH" "$SP_C3X_DEV_REPO" "$SP_C3X_DEV_DIR"

# Apply Patches
echo "Applying patches..."
git -C "$OP_DIR" apply ../../patches/openpilot.patch
echo "Patched openpilot."

git -C "$SP_C3X_STAGING_DIR" apply ../../patches/sunnypilot.patch
echo "Patched sunnypilot C3X staging."

git -C "$SP_C3_STAGING_DIR" apply ../../patches/sunnypilot.patch
echo "Patched sunnypilot C3 staging."

git -C "$SP_C3X_RELEASE_DIR" apply ../../patches/sunnypilot.patch
echo "Patched sunnypilot C3X release."


git -C "$SP_C3X_DEV_DIR" apply ../../patches/sunnypilot.patch
echo "Patched sunnypilot C3X dev."


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

# sunnypilot C3X staging
cd "$SP_C3X_STAGING_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git remote set-url origin "https://x-access-token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"
git add .
GIT_AUTHOR_DATE='2021-08-08 00:00:00 +0000' GIT_COMMITTER_DATE='2021-08-08 00:00:00 +0000' git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$SP_C3X_STAGING_PATCH_BRANCH" --force
cd -

# sunnypilot C3 staging
cd "$SP_C3_STAGING_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git remote set-url origin "https://x-access-token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"
git add .
GIT_AUTHOR_DATE='2021-08-08 00:00:00 +0000' GIT_COMMITTER_DATE='2021-08-08 00:00:00 +0000' git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$SP_C3_STAGING_PATCH_BRANCH" --force
cd -

# sunnypilot C3X release
cd "$SP_C3X_RELEASE_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git remote set-url origin "https://x-access-token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"
git add .
GIT_AUTHOR_DATE='2021-08-08 00:00:00 +0000' GIT_COMMITTER_DATE='2021-08-08 00:00:00 +0000' git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$SP_C3X_RELEASE_PATCH_BRANCH" --force
cd -


# sunnypilot C3X dev
cd "$SP_C3X_DEV_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git remote set-url origin "https://x-access-token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"
git add .
GIT_AUTHOR_DATE='2021-08-08 00:00:00 +0000' GIT_COMMITTER_DATE='2021-08-08 00:00:00 +0000' git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$SP_C3X_DEV_PATCH_BRANCH" --force
cd -

echo "Script finished."