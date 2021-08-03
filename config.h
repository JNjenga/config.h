/**
 * -----------
 * MIT License
 * -----------
 *
 * Copyright (c) 2021 Jnjenga
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
*/

namespace Cfg
{
	enum TokenType
	{
		COLON
	};

	struct Token
	{
		const char * tstring;
		TokenType tt;
	};

	struct AstNode
	{
		Token parent;
		Token lhs;
		Token rhs;
	};

	class Ast
	{
	public:
		AstNode & current();
		Token & lhs() const;
		Token & rhs() const;
		void step();
	private:
		uint32_t _caret;
		Token * _tokens;
	};

	void tokenize(const char * source, Token * const tokens, uint32_t size);
	Ast ast_from_tokens(Token * const tokens, uint32_t size);

	// TODO: Where to store the bindings?
	void create_bindings();
	void update_bindings();

	// Supported primitives
	uint32_t * const get_uint32_t(const char * name);
	uint16_t * const get_uint16_t(const char * name);
	uint8_t * const get_uint8_t(const char * name);
	float * const get_float(const char * name);
	double * const get_double(const char * name);
	char * const get_char(const char * name);

}

#ifdef CONFIG_IMPLEMENTATION

#endif
