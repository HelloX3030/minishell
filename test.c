#include <stdio.h>

static int	match_pattern(const char *pattern, const char *filename,
				char quotes);

static int	handle_star(const char *pattern, const char *filename, char quotes)
{
	while (*pattern == '*')
		pattern++;
	if (*pattern == '\0')
		return (1);
	while (*filename != '\0')
	{
		if (match_pattern(pattern, filename, quotes))
			return (1);
		filename++;
	}
	return (0);
}

static int	match_pattern(const char *pattern, const char *filename,
		char quotes)
{
	while (*pattern && *filename)
	{
		if (*pattern == '*' && quotes == 0)
			return (handle_star(pattern, filename, quotes));
		else if (*pattern == '\"' && quotes == 0)
			quotes = '\"';
		else if (*pattern == '\"' && quotes == '\"')
			quotes = 0;
		else if (*pattern == '\'' && quotes == 0)
			quotes = '\'';
		else if (*pattern == '\'' && quotes == '\'')
			quotes = 0;
		else if (*pattern != *filename && (quotes || *pattern != '?'))
			return (0);
		else
			filename++;
		pattern++;
	}
	if (*pattern == '\0' && *filename == '\0')
		return (1);
	else
		return (0);
}

struct		TestCase
{
	char	*pattern;
	char	*filename;
	int		expected;
};

int	main(void)
{
	int	num_tests;
	int	result;

	struct TestCase tests[] = {
		{"a*b", "ab", 1}, {"a*b", "acb", 1}, {"a*b", "a_b", 1}, {"a*b", "abc",
			1}, {"a*b", "a", 0}, {"a*b", "b", 0}, {"a?b", "acb", 1}, {"a?b",
			"ab", 0}, {"a?b", "aXb", 1}, {"*", "anything", 1}, {"a*b*c", "abc",
			1}, {"a*b*c", "axybzc", 1}, {"a*b*c", "ac", 1}, {"a*b*c", "a", 0},
			{"a*b*c", "bc", 0}, {"?b*", "ab", 1}, {"?b*", "bb", 1}, {"?b*",
			"cb", 1}, {"?b*", "b", 0}, {"*a", "aaa", 1}, {"*a", "ba", 1}, {"*a",
			"a", 1}, {"*a", "b", 0},
	};
	num_tests = sizeof(tests) / sizeof(tests[0]);
	for (int i = 0; i < num_tests; i++)
	{
		result = match_pattern(tests[i].pattern, tests[i].filename, 0);
		if (result != tests[i].expected)
		{
			printf("Test %d: Pattern = \"%s\", Filename = \"%s\" "
					"=> Expected: %d, Got: %d\n",
					i + 1,
					tests[i].pattern,
					tests[i].filename,
					tests[i].expected,
					result);
		}
	}
	return (0);
}

// int	main(void)
// {
// 	char	*pattern;
// 	char	*filename;
// 	int		expected;
// 	int		result;

// 	pattern = "a*b";
// 	filename = "ab";
// 	expected = 1;
// 	result = match_pattern(pattern, filename, 0);
// 	printf("Pattern = \"%s\", Filename = \"%s\" => Expected: %d, Got: %d\n",
// 		pattern, filename, expected, result);
// 	return (0);
// }
