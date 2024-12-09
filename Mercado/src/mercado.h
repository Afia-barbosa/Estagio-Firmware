typedef struct {
	int codigo;
	char nome[30];
	float preco;
}Produto;

typedef struct{
	Produto produto;
	int quantidade;
} Carrinho;

void infoProduto(Produto prod);
void menu();
void cadastrarProduto();
void listarProduto();
void comprarPorduto();
void visualizarItemCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int * temNoCarrinho(int codigo);
void fecharPedido();

static int contador_produto;
static int contador_carrinho;
static Carrinho carrinho[50];
static Produto produtos[50];
