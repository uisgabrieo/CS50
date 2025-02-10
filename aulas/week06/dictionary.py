words = set()

def check(word: str) -> bool:
    return word.lower() in words


def load(dictionary: str) -> bool:
    try:
        with open(dictionary, "r") as dictionary_file:
            words.update(dictionary_file.read().splitlines())
        return True
    except:
        return False

def size() -> int:
    return len(words)

def unload() -> bool:
    return True
