def solution(cacheSize, cities):

    if cacheSize == 0:
        return len(cities) * 5
    cache = []
    answer = 0

    cities = [city.lower() for city in cities]

    for city in cities:
        is_is_cache = city in cache
        if is_is_cache:
            # 캐시에 있는거 빼서 맨뒤에 추가
            if len(cache) == cacheSize:
                cache.remove(city)
            cache.append(city)
            answer += 1
        else:
            # 캐시에서 제일 오래 된 거 빼고 이거 추가
            if len(cache) == cacheSize:
                cache.pop(0)
            cache.append(city)
            answer += 5

    return answer
