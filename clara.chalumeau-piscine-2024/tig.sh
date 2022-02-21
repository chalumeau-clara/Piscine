set -e
git commit -m "$1"
git tag -a "$2" -m "$1"
git push
git push --tags
