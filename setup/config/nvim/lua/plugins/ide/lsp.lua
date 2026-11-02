return {
  {
    "neovim/nvim-lspconfig",
    opts = {
      servers = {
        pyright = {},
        clangd = {},
        marksman = {},
        -- asm_lsp = {
        --   cmd = { "asm-lsp" },
        --   filetypes = { "asm", "s", "S" },
        --   settings = {
        --     asm = {
        --       architecture = "riscv32",
        --       assembler = "riscv32-unknown-elf-as",
        --     },
        --   },
        -- },
      },
    },
  },
  {},
}
