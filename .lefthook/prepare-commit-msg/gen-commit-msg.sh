case "$2" in
  ''|'{2}')
    tmp=$(mktemp "${1}.XXXXXX") || exit 1
    trap 'rm -f "$tmp"' 0
    { date +'working on leetcode %Y/%m/%d %H:%M:%S' && sed '/[^[:space:]]/,$!d' "$1"; } > "$tmp" && mv -f "$tmp" "$1"
    ;;
esac
