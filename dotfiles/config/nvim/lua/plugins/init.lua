return {
  { import = "plugins.ide" },
  {
    "mason-org/mason.nvim",
    opts = {
      ensure_installed = {
        -- lua
        "stylua",
        -- C/Cpp
        "clangd",
        "clang-format",
        "cpptools",
        "cpplint",
        -- Bash
        "shellcheck",
        "shfmt",
        -- Python
        "pyright",
        "flake8",
      },
    },
  },
}
